#include "inc.hh"

void files::remove( const std::filesystem::path path_log )
{
	std::error_code ec;
	const auto removed = std::filesystem::remove_all( path_log, ec );

	if( !ec )
	{
		if( removed )
			std::cout << "	[+] " << path_log << " removed.\n";	
	}
	else
	{
		std::cout << "	[!] " << path_log << " failed to remove.\n";	
	}
}

void files::clear_logs( )
{
	std::cout << "[-] Deleting League logs...\n";

	std::filesystem::path paths[ ] = {
		R"(C:\ProgramData\Riot Games)",
		R"(C:\ProgramData\Riot Games\machine.cfg)",
		R"(C:\Riot Games\League of Legends\Config)",
		R"(C:\Riot Games\League of Legends\Logs)",
		R"(C:\Riot Games\League of Legends\debug.log)",
		R"(C:\Riot Games\Riot Client\UX\natives_blob.bin)",
		R"(C:\Riot Games\Riot Client\UX\snapshot_blob.bin)",
		R"(C:\Riot Games\Riot Client\UX\v8_context_snapshot.bin)",
		R"(C:\Riot Games\Riot Client\UX\icudtl.dat)",
		""
	};

	auto appdata = std::filesystem::temp_directory_path( ).parent_path( ).parent_path( );
	appdata /= "Riot Games";
	paths[ 9 ] += appdata;

	for( const auto& path : paths )
		files::remove( path );
}

void files::clear_computer()
{
	std::cout << "[-] Cleaning computer...\n";

	std::filesystem::path paths[] = {

		R"(C:\Riot Games\Riot Client\UX\Plugins\plugin-manifest.json)",
		R"(C:\Windows\win.ini)",
		R"(C:\ProgramData\Microsoft\Windows\DeviceMetadataCache\dmrc.idx)",
		R"(C:\System Volume Information\tracking.log)",
		R"(C:\Users\user\AppData\Local\Microsoft\Vault\UserProfileRoaming\Latest.dat)",
		R"(C:\Users\user\\AppData\Local\AC\INetCookies\ESE\container.dat)",
		R"(C:\Users\user\\AppData\Local\UnrealEngine\4.23\Saved\Config\WindowsClient\Manifest.ini)",
		R"(C:\Users\user\\AppData\Local\Microsoft\OneDrive\logs\Common\DeviceHealthSummaryConfiguration.ini)",
		R"(C:\ProgramData\Microsoft\Windows\DeviceMetadataCache\dmrc.idx)",
		R"(C:\Users\user\\ntuser.ini)",
		R"(C:\Users\user\\AppData\Local\Microsoft\Windows\INetCache\IE\container.dat)",
		""
	};

	for (const auto& path : paths)
	{
		files::remove( path );
	}

}

void files::clear_temp()
{
	
	std::cout << "[-] Cleaning temp...\n";

	std::error_code errorCode;

	int counter = 0;
	for (const auto& file : std::filesystem::directory_iterator(std::filesystem::temp_directory_path()))
	{
		std::filesystem::remove_all(file, errorCode);
		counter++;
	}
	
	std::cout << "[+] Deleted " + std::to_string(counter) + " files in temp directory\n";

}