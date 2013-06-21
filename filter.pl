
while ( $line = <STDIN> ) {

  $line =~ s/\x0d//g;
  print $line;

}
