

#include<iostream>
#include<fstream>
#include<mutex>
#include<string>
#include<sstream>
#include<ctime>
#include<stdexcept>
#include<iomanip>
#include<Windows.h>
#include<cassert>

#if !defined(__JL_LOGFILE_HEADER__)
#define __JL_LOGFILE_HEADER__

#include"Message.h"

#define MSG_DIV "----------------------------------------------------"
#define MSG_DIV2 "*******************************************************************************************************"
#define MSG_NEWLOGGING_SESSION "NEW LOGGING SESSION STARTED"
#define MSG_CLOSELOGGIN_SESSION "CLOSING LOGGING SESSION"
#if !defined(MESSAGE_SOURCE)
#define MESSAGE_SOURCE jl::Message_source(JL_FILENAME, __FUNCTION__, __LINE__)
#endif
#if !defined(INFO)
#define INFO(Message_desc) jl::Info_message(MESSAGE_SOURCE, Message_desc)
#endif
#if !defined(INFO_MESSAGE)
#define INFO_MESSAGE(Message_desc) jl::Info_message(MESSAGE_SOURCE, Message_desc)
#endif
#if !defined(SYS_ERROR_MESSAGE)
#define SYS_ERROR_MESSAGE(Sys_error_code) jl::System_error_message(MESSAGE_SOURCE, Sys_error_code)
#endif

#if !defined(SYSERR)
#define SYSERR(Sys_error_code) jl::System_error_message(MESSAGE_SOURCE, Sys_error_code)
#endif

#if !defined(USR_ERROR_MESSAGE)
#define APP_ERROR_MESSAGE(Message_desc) jl::Application_error_message(MESSAGE_SOURCE, Message_desc)
#endif

#if !defined(APPERR)
#define APPERR(Message_desc) jl::Application_error_message(MESSAGE_SOURCE, Message_desc)
#endif
namespace jl {

	class Log_file {
	public:
		DLLEXPORT Log_file(const char* File_name);
		Log_file(const Log_file&) = delete;
		DLLEXPORT ~Log_file();
		DLLEXPORT virtual void log_message(const char* Message_source, const char* Message);
		DLLEXPORT virtual void log_message(const char* Message_source, const int& MS_error_code);
		DLLEXPORT virtual void log_message(const Message& Msg);
	protected:
		std::mutex Append_mutx;
		std::ofstream log;
		DLLEXPORT struct std::tm get_localtime() const;
	};
};
#endif