#!perl -w

use strict;

#my $filepath = "C:/Users/ASPePeX/Downloads/blender-2.72b/blender-2.72b/source/blender/makesrna/intern";
my $filepath = "E:/Dropbox/HS Furtwangen/Allgemein/FUSEE/ExternalProjects/blender/source/blender/makesrna/intern";

my @alltherna;
my @allthemaps;
my @allthefunc;

opendir(IN, $filepath);
my @dir = readdir(IN);
closedir(IN);

# mapping
foreach my $file (@dir)
	{
	if ($file =~ /RNA_/gi)
		{
#		print $file . "\n";
		open(IN, "<$filepath/$file");
		my @filecontent = <IN>;
		close(IN);

		foreach my $line (@filecontent)
			{
			if ($line =~ /(RNA_def_\w*)/g)
				{
				push(@alltherna, lc $1);
				push(@allthemaps, lc "rna_def_map[\"" . $1 . "\"] = "  . $1 . ";\n");
				}
			}		
		}
	}
my @uniquerna = sort(uniq(@alltherna));
my @uniquemaps = sort(uniq(@allthemaps));

open(OUT, ">rnalist.txt");
print OUT @uniquemaps;
close OUT;

# functions
foreach my $rna (@uniquerna)
	{
		push(@allthefunc, lc "bool ". $rna ."(vector<bpy_func> &funcs, string str)\n{\n\treturn false;\n}\n\n");
	}

open(OUT, ">rnafunc.txt");
print OUT @allthefunc;
close OUT;

sub uniq
	{
	my %seen;
	grep !$seen{$_}++, @_;
	}