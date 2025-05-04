#ifndef UI_INC_UI_HANDLER_H_
#define UI_INC_UI_HANDLER_H_

#include <Eigen/Dense>
#include <QList>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include "inc/measurement_range_bearing.h"
#include "inc/multi_tracker_gnn.h"
#include "inc/multi_tracker_jpda.h"
#include "inc/multi_tracker_mht.h"
#include "inc/tracker_gaussian_sum.h"
#include "inc/tracker_nn.h"
#include "inc/tracker_pda.h"
#include "inc/transition_2d_turn.h"

using Eigen::MatrixXd;
using Eigen::Vector2d;
using Eigen::VectorXd;
using std::make_shared;
using std::shared_ptr;

class UIHandler : public QObject {
  Q_OBJECT
 public:
  explicit UIHandler(const QQmlApplicationEngine &engine,
                     QObject *parent = nullptr);
  ~UIHandler() = default;

 protected:
  shared_ptr<Vector2d> s;
  shared_ptr<MatrixXd> range_c;
  int nbirths;

  shared_ptr<TrackerNN> tracker_nn;
  shared_ptr<TrackerPDA> tracker_pda;
  shared_ptr<TrackerGaussianSum> tracker_gaussian_sum;

  shared_ptr<MultiTrackerGNN> tracker_gnn;
  shared_ptr<MultiTrackerJPDA> tracker_jpda;
  shared_ptr<MultiTrackerMHT> tracker_mht;

 signals:

  void multiTrackingAddItem(QString typeOfItem, QList<qreal> x, QList<qreal> y);
  void singleTrackingAddItem(QString typeOfItem, qreal x, qreal y);

 public slots:

  void initSingleTrackers(int x1, int y1, int x2, int y2, int lambda_c);

  void initMultiTrackers(QList<int> lst_x_1, QList<int> lst_y_1,
                         QList<int> lst_x_2, QList<int> lst_y_2, int nbirths,
                         int lambda_c);

  void singleMeasurements(QList<int> xs, QList<int> ys);

  void multiMeasurements(QList<int> xs, QList<int> ys);
};

#endif  // UI_INC_UI_HANDLER_H_