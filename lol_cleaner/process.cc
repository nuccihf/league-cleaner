#include "inc.hh"

void process::close( std::string process_name )
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof( PROCESSENTRY32 );

	const auto snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPALL, NULL );

	for( Process32First( snapshot, &entry ); Process32Next( snapshot, &entry ); )
	{
		if( entry.szExeFile == process_name )
		{
			const auto handle_process = OpenProcess( PROCESS_TERMINATE, FALSE, entry.th32ProcessID );
			TerminateProcess( handle_process, 0 );
			CloseHandle( handle_process );
			std::cout << "	[+] " << process_name << " closed.\n";
		}
	}

	CloseHandle( snapshot );

}

void process::close_all(  )
{
	std::cout << "[-] Stopping Riot Games & League of Legends processes...\n";

	std::string processes[ ] = {
		"LeagueCrashHandler.exe",
		"League of Legends.exe",
		"LeagueClientUxRender.exe",
		"LeagueClientUx.exe",
		"LeagueClient.exe",
		"RiotClientServices.exe"
	};

	for( const auto& process : processes )
		process::close( process );

	std::this_thread::sleep_for(std::chrono::seconds(2));

}

std::string process::gen_string(const int length)
{
	std::string GeneratedString;
	static const char Alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; i++)
		GeneratedString += Alphabet[rand() % (sizeof(Alphabet) - 1)];
	return GeneratedString;
}