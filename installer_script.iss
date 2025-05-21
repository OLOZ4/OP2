[Setup]
AppName=Benediktas-Juozapaitis
AppVersion=1.0
DefaultDirName={pf}\VU\Benediktas-Juozapaitis
DefaultGroupName=VU\Benediktas-Juozapaitis
OutputDir=.
OutputBaseFilename=Setup_BenediktasJuozapaitis
Compression=lzma
SolidCompression=yes

[Files]
Source: "main.exe"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Benediktas-Juozapaitis"; Filename: "{app}\MyApp.exe"
Name: "{commondesktop}\Benediktas-Juozapaitis"; Filename: "{app}\MyApp.exe"