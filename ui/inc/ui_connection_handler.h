#ifndef UI_INC_UI_CONNECTION_HANDLER_H_
#define UI_INC_UI_CONNECTION_HANDLER_H_

#include <QDebug>
#include <QObject>
#include <QTimer>

class UIConnectionHandler : public QObject {
  Q_OBJECT
 public:
  explicit UIConnectionHandler(QObject* parent = nullptr);
  ~UIConnectionHandler() = default;
 public slots:
  void update();
  void receiveFromQml(QString value);

 private:
  int counter;

 signals:
  void addData(QString typeOfDraw, qreal x, qreal y);
  void addData(QString typeOfDraw, QList<int>& x, QList<int>& y);
  void recvData(QString text);
  void hello();
};

#endif  // UI_INC_UI_CONNECTION_HANDLER_H_
