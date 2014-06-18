// -*- C++ -*-
/*!
 * @file  DoubleSeqLogger.cpp
 * @brief Logger Componet for DoubleSeq datatype
 * @date $Date$
 *
 * $Id$
 */

#include "DoubleSeqLogger.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <time.h>
// Module specification
// <rtc-template block="module_spec">
static const char* doubleseqlogger_spec[] =
  {
    "implementation_id", "DoubleSeqLogger",
    "type_name",         "DoubleSeqLogger",
    "description",       "Logger Componet for DoubleSeq datatype",
    "version",           "1.0.0",
    "vendor",            "ogata-lab",
    "category",          "Experimental",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "100",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.console_print", "0",
    "conf.default.logdir", "log", 
    // Widget
    "conf.__widget__.console_print", "text",
    // Constraints
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
DoubleSeqLogger::DoubleSeqLogger(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
DoubleSeqLogger::~DoubleSeqLogger()
{
}



RTC::ReturnCode_t DoubleSeqLogger::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("console_print", m_console_print, "0");
  bindParameter("logdir", m_logdir, "log");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DoubleSeqLogger::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DoubleSeqLogger::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DoubleSeqLogger::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t DoubleSeqLogger::onActivated(RTC::UniqueId ec_id)
{
  std::cout << "[RTC.DoubleSeqLogger] Activated" << std::endl;
  time_t timer;
  time(&timer);
  struct tm *t = localtime(&timer);
  std::ostringstream oss;

  oss << m_logdir << "/" << "doubleseq_" << t->tm_year+1900;
  oss << std::setw(2) << std::setfill('0') ;
  oss << t->tm_mon+1 << t->tm_mday << t->tm_hour << t->tm_min << t->tm_sec << ".log";
  std::string filename = oss.str();
  std::cout << "[RTC.DoubleSeqLogger] Saving File to " << filename << std::endl;
  m_FileOut.open(filename);
  if (m_FileOut.fail()) {
    std::cout << "[RTC.DoubleSeqLogger] Failed to open file (" << filename << ")" << std::endl;
    return RTC::RTC_ERROR;
  }
  m_Init = false;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DoubleSeqLogger::onDeactivated(RTC::UniqueId ec_id)
{
  std::cout << "[RTC.DoubleSeqLogger] Deactivated" << std::endl;
  if (!m_FileOut.fail()) {
    m_FileOut.close();
  }

  return RTC::RTC_OK;
}


RTC::ReturnCode_t DoubleSeqLogger::onExecute(RTC::UniqueId ec_id)
{
  if (m_inIn.isNew()) {
    m_inIn.read();
    if (!m_Init) { // Write Label Row
      m_FileOut << "Sec, NanoSec, ";
      for (int i = 0;i < m_in.data.length();i++) {
	m_FileOut << i;
	if (i != m_in.data.length()-1) {
	  m_FileOut << ", ";
	} else {
	  m_FileOut << "\n";
	}
      }
      m_Init = true;
    }
    m_FileOut << m_in.tm.sec << ", " << m_in.tm.nsec << ", ";
    for (int i = 0;i < m_in.data.length();i++) {
      m_FileOut << m_in.data[i];
      if (i != m_in.data.length()-1) {
	m_FileOut << ", ";
      } else {
	m_FileOut << "\n";
      }
    }
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DoubleSeqLogger::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DoubleSeqLogger::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DoubleSeqLogger::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DoubleSeqLogger::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DoubleSeqLogger::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void DoubleSeqLoggerInit(RTC::Manager* manager)
  {
    coil::Properties profile(doubleseqlogger_spec);
    manager->registerFactory(profile,
                             RTC::Create<DoubleSeqLogger>,
                             RTC::Delete<DoubleSeqLogger>);
  }
  
};


