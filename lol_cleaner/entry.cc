#include "inc.hh"

int main( )
{
	// Console title
	//
	SetConsoleTitle( process::gen_string(16).c_str() );

	// Hello 
	//
	std::cout << "[+] Cleaner started...\n";

	// close processes
	//
	process::close_all( );

	// clear logs
	//
	files::clear_logs( );

	// clear computer
	//
	files::clear_computer();

	// clear temp
	//
	files::clear_temp();

	// Bye 
	//
	std::cout << "You are safe now, fuck with Riot :)";
	std::this_thread::sleep_for( std::chrono::seconds( 6 ) );

	return EXIT_SUCCESS;
}