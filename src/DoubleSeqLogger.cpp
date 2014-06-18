// -*- C++ -*-
/*!
 * @file  DoubleSeqLogger.cpp
 * @brief Logger Componet for DoubleSeq datatype
 * @date $Date$
 *
 * $Id$
 */

#include "DoubleSeqLogger.h"

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
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DoubleSeqLogger::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DoubleSeqLogger::onExecute(RTC::UniqueId ec_id)
{
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


