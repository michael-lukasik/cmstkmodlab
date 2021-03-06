/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//               Copyright (C) 2011-2019 - The DESY CMS Group                  //
//                           All rights reserved                               //
//                                                                             //
//      The CMStkModLab source code is licensed under the GNU GPL v3.0.        //
//      You have the right to modify and/or redistribute this source code      //
//      under the terms specified in the license, which may be found online    //
//      at http://www.gnu.org/licenses or at License.txt.                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#ifndef THERMO2DAQTHREAD_H
#define THERMO2DAQTHREAD_H

#include <QObject>
#include <QThread>

#include "Thermo2DAQModel.h"

class Thermo2DAQThread : public QThread
{
public:
  explicit Thermo2DAQThread(Thermo2DAQModel* daqModel,
                            QObject *parent = 0);
public:
  void run();

protected:
  Thermo2DAQModel* daqModel_;
};

#endif // THERMO2DAQTHREAD_H
