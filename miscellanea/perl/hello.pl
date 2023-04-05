#!/usr/bin/perl

use strict;
use warnings;
use utf8;
use Data::Dumper;

$a = 'Hello, World!\n'; # Escape sequence does not work for single quotation
$b = "Hello, World!\t aaa\n";
print $a."\n"; # dot operator is used to concatenate strings
print $b;
print "a"x3, "\n"; # lower case x for string multiplication, use , to 

my $one = '1';
my $two = '2'; # In perl numbers are strings
print $one + $two, "\n"; # plus operator is used to add numbers

my $three = 3;
my $four = 4; 
print $three . $four, "\n"; # dot operator is used to concatenate strings

for (our $i = 0; $i < 10; $i++) {
	print $i, " ";
}
print "\n";

for my $j (0..3) {
	$three +=1; # perl has increment operator
	print $j, ": ", $three, "\n"; # increment operator
}

my $name = "Harry";
my $name_ref = \$name; # reference to a scalar: prefix with \$
my $de_ref = $$name_ref; # de-reference a scalar: prefix with $$
print $name_ref, "\n"; # print the reference
print $de_ref, "\n"; # print the de-referenced value
print $$name_ref, "\n"; # print the de-referenced value

# print "Data Dumper: \n";
print (warn Dumper \$name_ref, "\n"); # print the reference

if  ($name eq "Harry") { # eq is used to compare strings
	print "Hello, Harry!\n";
} else {
	print "Hello, stranger!\n";
}

# File I/O
open(my $fh, '>out.txt');
print $fh "hello world\n";
print $fh "this is simple file writing\n";
close($fh);

