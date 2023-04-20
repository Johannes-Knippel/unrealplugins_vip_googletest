Write-Host "  ooooooooo.   oooo                                  o8o                                 "
Write-Host "  *888   *Y88. *888                                  ***                                 "
Write-Host "   888   .d88*  888  oooo  oooo   .oooooooo         oooo  ooo. .oo.                      "
Write-Host "   888ooo88P*   888  *888  *888  888* *88b          *888  *888P*Y88b                     "
Write-Host "   888          888   888   888  888   888  8888888  888   888   888                     "
Write-Host "   888          888   888   888  *88bod8P*           888   888   888                     "
Write-Host "  o888o        o888o  *V88V*V8P* *8oooooo.          o888o o888o o888o                    "
Write-Host "                                 d*     YD                                               "
Write-Host "                                 *Y88888P*                                               "
Write-Host "                                                                                         "
Write-Host "  ooooooooooooo                                        oooo                .             "
Write-Host "  8*   888   *8                                        *888              .o8             "
Write-Host "       888       .ooooo.  ooo. .oo.  .oo.   oo.ooooo.   888   .oooo.   .o888oo  .ooooo.  "
Write-Host "       888      d88* *88b *888P*Y88bP*Y88b   888* *88b  888  *P  )88b    888   d88* *88b "
Write-Host "       888      888ooo888  888   888   888   888   888  888   .oP*888    888   888ooo888 "
Write-Host "       888      888    .o  888   888   888   888   888  888  d8(  888    888 . 888    .o "
Write-Host "      o888o     *Y8bod8P* o888o o888o o888o  888bod8P* o888o *Y888**8o   *888* *Y8bod8P* "
Write-Host "                                             888                                         "
Write-Host "                                            o888o                                        "
Write-Host "                                                                                         "
Write-Host "  ooooooooo.                                                                             "
Write-Host "  *888   *Y88.                                                                           "
Write-Host "   888   .d88*  .ooooo.  ooo. .oo.    .oooo.   ooo. .oo.  .oo.    .ooooo.  oooo d8b      "
Write-Host "   888ooo88P*  d88* *88b *888P*Y88b  *P  )88b  *888P*Y88bP*Y88b  d88* *88b *888**8P      "
Write-Host "   888*88b.    888ooo888  888   888   .oP*888   888   888   888  888ooo888  888          "
Write-Host "   888  *88b.  888    .o  888   888  d8(  888   888   888   888  888    .o  888          "
Write-Host "  o888o  o888o *Y8bod8P* o888o o888o *Y888**8o o888o o888o o888o *Y8bod8P* d888b         "
Write-Host "                                                                                         "
Write-Host "                                                                                         "



$NewPluginName = Read-Host "Please enter the name of your new plug-in"
$TextToReplace = "VIPGoogleTestTemplate"
$NewPluginNameInUpperCase = $NewPluginName.ToUpper()
$TextToReplaceInUpperCase = $TextToReplace.ToUpper()
$SubfolderPath = ".\VIPGoogleTestTemplate"


#Rename all files
$TotalFileCounter = 0
$RenamedFileCounter = 0
Write-Host "-----------------------------------------------------------------"
Write-Host "Renaming all files containing the word" $TextToReplace "..."
Get-ChildItem -File -Recurse -Path $SubfolderPath | % {
	if ($_.Name.contains($TextToReplace)){
		$RenamedFileCounter++
	}
	Rename-Item -Path $_.PSPath -NewName $_.Name.replace($TextToReplace, $NewPluginName)
	$TotalFileCounter++
}
Write-Host "Checked " $TotalFileCounter " Files and renamed " $RenamedFileCounter " of them.`n-----------------------------------------------------------------"




#Replace file contents
$TotalFileCounter = 0
$OccuranceCounter = 0
Write-Host "Replacing the word" $TextToReplace "in all the files..."
Get-ChildItem -File -Recurse -Path $SubfolderPath | % {
	#the icons need to be excluded because they somehow break otherwise
	if (!($_.Name.contains("Icon"))){
		$OccuranceCounter += ([regex]::Matches((Get-Content $_.PSPath), $TextToReplace )).count
		(Get-Content $_.PSPath).replace($TextToReplace, $NewPluginName) | Set-Content $_.PSPath
		$TotalFileCounter++
	}
}
Write-Host "Checked" $TotalFileCounter "Files and replaced the word" $TextToReplace $OccuranceCounter "times.`n-----------------------------------------------------------------"


#Replace UPPERCASE file contents
$TotalFileCounter = 0
$OccuranceCounter = 0
Write-Host "Some Modules are named in all caps."
Write-Host "So now all occurances of the word" $TextToReplaceInUpperCase "will be replaced with the word" $NewPluginNameInUpperCase "..."
Get-ChildItem -File -Recurse -Path $SubfolderPath | % {
	#the icons need to be excluded because they somehow break otherwise
	if (!($_.Name.contains("Icon"))){
		$OccuranceCounter += ([regex]::Matches((Get-Content $_.PSPath), $TextToReplaceInUpperCase )).count
		(Get-Content $_.PSPath).replace($TextToReplaceInUpperCase, $NewPluginNameInUpperCase) | Set-Content $_.PSPath
		$TotalFileCounter++
	}
}
Write-Host "Checked" $TotalFileCounter "Files and replaced the word" $TextToReplaceInUpperCase $OccuranceCounter "times.`n-----------------------------------------------------------------"



#Rename all directories
$TotalDirectoryCounter = 0
$RenamedDirectoryCounter = 0
Write-Host "Renaming all directories containing the word" $TextToReplace "..."
Get-ChildItem -Directory -Recurse | % {
	if ($_.Name.contains($TextToReplace)){
		$RenamedDirectoryCounter++
	}
	Rename-Item -Path $_.PSPath -NewName $_.Name.replace($TextToReplace, $NewPluginName) -ErrorAction SilentlyContinue
	$TotalDirectoryCounter++
}
Write-Host "Checked " $TotalDirectoryCounter " Directories and renamed " $RenamedDirectoryCounter " of them.`n-----------------------------------------------------------------"


Write-Host "Renaming finished."
Read-Host -Prompt "Press Enter to exit"