// Meta
#include "meta/binding_to_func_demo.h"
#include "meta/connect_std_bind.h"
#include "meta/invoke_method_usage.h"
#include "meta/connect_lambda_expr.h"
#include "meta/invoke_func_on_specific_thread.h"
#include "meta/invoke_func_on_main_thread.h"
#include "meta/qobject_cast_sender.h"


// Core
#include "core/q_foreach_macro.h"
#include "core/debug_messages.h"
#include "core/get_appinstance_anywhere.h"

// System
#include "system/basic_info.h"


// Io


// FileSystem
#include "filesystem/create_red_image.h"
#include "filesystem/delete_file.h"
#include "filesystem/dir_cd_create.h"
#include "filesystem/dir_iterastor_demo.h"
#include "filesystem/file_exists.h"
#include "filesystem/file_size_demo.h"
#include "filesystem/get_all_drives.h"
#include "filesystem/qdir_cleanpath_demo.h"
#include "filesystem/remove_all_images.h"
#include "filesystem/special_paths_demo.h"
#include "filesystem/standard_path_temp_demo.h"

// Concurrent
#include "concurrent/qttimer_lambda.h"
#include "concurrent/exec_on_ui_thread_timer.h"
#include "concurrent/qt_concurrent_blockingmapped_usage.h"
#include "concurrent/qtconcurrent_run_user.h"
#include "concurrent/qthread_lambda_qeventloop.h"
#include "concurrent/not_ready/qtimer_qprocess.h"


// Data structures
#include "data_structures/qstringlist_demo.h"
#include "data_structures/qvector_demo.h"
#include "data_structures/qbyte_arrays_forloopscan.h"


// Process
#include "process/qprocess_wmi_list_processes.h"


// Database
#include "database/mysql_connection_select.h"


// Crypto
#include "crypto/file_md5_hash.h"
#include "crypto/str_md5_hash.h"


// Time
#include "time/date_to_format.h"
#include "time/about_current_date.h"


int main(int argc, char* argv[])
{
	// Concurrent
	// QTimerLambda::main();
	// ExecOnUiThreadTimer::main();
	// QtConcurrentBlockingMappedDemo::main(); // Not working
	// QtConcurrentBlockingMappedUsage::main();
	// QtConcurrentRunUsage::main();
	// QThreadLambdaAndQEventLoop::main();
	// ProcessAndTimerLambdaDemo::main(); // Not working


	// Core
	// QForeachMacroDemo::main();
	// StdOutMessageTypes::main();
	// GetAppInstanceDemo::main(argc, argv);


	// Crypto
	// Md5FromFile::main();
	// Md5FromString::main();


	// DataStructures
	// QByteArrayScanDemo::main();
	// QStringListUsage::main();
	// QVectorUsage::main();


	// Database
	// MySQLConnectionSelect::main();
	// QSQLiteAllOperations::main();


	// Filesystem
	// CreateRedImage::main();
	// DeleteFile::main();
	// DirCdCreateDemo::main();
	// DirRecursiveIteratorDemo::main();
	// CheckFileExists::main();
	// GetFileSizeQFileInfo::main();
	// GetAllDrives::main();
	// GetDirCleanPath::main();
	// RemoveAllImagesDemo::main();
	// GetHomePath::main();
	// GetStandardTempPath::main();


	// IO
	// return SerializationDemo::main();
	// return SerializationDemoFile::main();
	// return SysBasicInfo::main();


	// Meta
	// BindingToFuncNonQObject::main();
	// ConnectStdBind::main();
	// ConnectLambda::main();
	// InvokeFuncOnMainThread::main();
	// InvokeFuncInSpecificThread::main();
	// InvokeMethodUsage::Worker::main();
	// QCastObjectSender::Launcher::main();


	// Net


	// 
	// Process
	GetProcessListWmic::main();


	// System
	// GetSystemBasicInfo::main();


	// Text


	// Time
	// AboutCurrentDate::main();
	GetFormattedDateString::main();
}
