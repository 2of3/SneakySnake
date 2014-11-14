#!perl -w

use strict;

open (BLA, "<C:/Users/ASPePeX/Downloads/blender-2.72b/blender-2.72b/source/blender/makesrna/intern/rna_object_api.c");
my @bla = <BLA>;
close BLA;

my $x = "";

foreach my $blub (@bla)
	{
	$blub =~ s/\/\*.*\*\///g; # Kommentare entfernen
	$blub =~ s/^\s+|\s+$//g; # Whitespace vor und nach String entfernen
	
	$blub = $x . $blub;
	
	if ($blub =~ /RNA_def/g) # Prüft auf RNA_def
		{
		if ($blub =~ /\);/g) # Prüft auf Zeilenende mit: );
			{
			$blub = $blub . "\n";
			print $blub; # Output
			$x = "";
			}
		else 
			{
			$x = $blub;
			}
		}
	}
