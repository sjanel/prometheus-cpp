#pragma once

#include <atomic>

#include "prometheus/client_metric.h"
#include "prometheus/metric_type.h"

namespace prometheus {

/// \brief A gauge metric to represent a value that can arbitrarily go up and
/// down.
///
/// The class represents the metric type gauge:
/// https://prometheus.io/docs/concepts/metric_types/#gauge
///
/// Gauges are typically used for measured values like temperatures or current
/// memory usage, but also "counts" that can go up and down, like the number of
/// running processes.
class Gauge {
 public:
  static const MetricType metric_type = MetricType::Gauge;

  /// \brief Create a gauge that starts at 0.
  Gauge();

  /// \brief Create a gauge that starts at the given amount.
  Gauge(double);

  /// \brief Increment the gauge by 1.
  void Increment();

  /// \brief Increment the gauge by the given amount.
  void Increment(double);

  /// \brief Decrement the gauge by 1.
  void Decrement();

  /// \brief Decrement the gauge by the given amount.
  void Decrement(double);

  /// \brief Set the gauge to the given value.
  void Set(double);

  /// \brief Set the gauge to the current unixtime in seconds.
  void SetToCurrentTime();

  /// \brief Get the current value of the gauge.
  double Value() const;

  ClientMetric Collect();

 private:
  void Change(double);
  std::atomic<double> value_;
};

}  // namespace prometheus
