#ifndef COMMUNICATIONSERVER_H
#define COMMUNICATIONSERVER_H

#include <vector>

#include <QMutex>
#include <QTcpServer>
#include <QTcpSocket>

#include <PumpStationModel.h>

class CommunicationServer : public QTcpServer
{
  Q_OBJECT

public:

  CommunicationServer(PumpStationModel* model,
                      QObject *parent = 0);

protected slots:

  void handleCommand();

signals:

  void setSwitchEnabled(int channel, bool enabled);
  void setSwitchBlocked(int channel, bool blocked);
  void setPumpOperatingHours(int, double);

protected:

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
  void incomingConnection(int socketDescriptor);
#else
  void incomingConnection(qintptr socketDescriptor);
#endif

  PumpStationModel* model_;

  std::vector<int> pumpChannels_;
  std::vector<int> valveChannels_;

  QTcpSocket* socket_;
  QMutex mutex_;
};

#endif // COMMUNICATIONSERVER_H

