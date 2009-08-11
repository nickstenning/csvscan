# -*- ruby -*-

require 'rubygems'
require 'hoe'

class CSVScan
  VERSION = "0.1.0"
end

Hoe.spec 'csvscan' do
  developer('Ben Sandofsky', 'sandofsky@gmail.com')
  spec_extras[:extensions] = "ext/csvscan/extconf.rb"
  clean_globs << "ext/csvscan/csvscan.*" << "ext/csvscan/*.o" << "ext/Makefile"
end

# vim: syntax=ruby
