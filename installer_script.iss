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
Source: "program\main.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\Benediktas-Juozapaitis"; Filename: "{app}\program\main.exe"
Name: "{commondesktop}\Benediktas-Juozapaitis"; Filename: "{app}\program\main.exe"