#!perl -w

open (BLA, "<rna_object_api.c");
@bla = <BLA>;
close BLA;

$x = "";

foreach $blub (@bla)
	{
	$blub =~ s/\/\*.*\*\///g; # Kommentare entfernen
	$blub =~ s/^\s+|\s+$//g; # Whitespace vor und nach String entfernen
	
	$blub = $x . $blub;
	
	if ($blub =~ /RNA_def/g) # Pr�ft auf RNA_def
		{
		if ($blub =~ /\);/g) # Pr�ft auf Zeilenende mit: );
			{
			$blub = $blub . "\n";
			print $blub); # Output
			$x = "";
			}
		else 
			{
			$x = $blub;
			}
		}
	}
