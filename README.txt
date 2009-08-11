= csvscan

http://github.com/sandofsky/csvscan

== DESCRIPTION:

This is a packaged version of CSVScan, written by MoonWolf. If you can read Japanese, checkout README.ja for whatever he said.

On a 10,000 line file:

    time cat example.csv | ruby fastercsv_benchmark.rb

    real	0m8.804s
    user	0m8.502s
    sys	0m0.304s

    time cat example.csv | ruby csvscan_benchmark.rb 

    real	0m0.860s
    user	0m0.782s
    sys	0m0.088s


== FEATURES/PROBLEMS:

* First version.
* I have not tested this on Windows, and have no intention to.

== SYNOPSIS:

    require 'csvscan'
    CSVScan.scan(STDIN) do |row|
        puts row.inspect
    end

== REQUIREMENTS:

* FIX (list of requirements)

== INSTALL:

* gem install sandofsky-csvscan --source http://gems.github.com

== LICENSE:

Looks like the original source was LGPL, so I'm stuck with that.