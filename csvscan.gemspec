Gem::Specification.new do |s|
  s.name = %q{csvscan}
  s.version = "0.1.0"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.authors = ["Ben Sandofsky"]
  s.date = %q{2009-08-11}
  s.description = %q{This is a packaged version of CSVScan, written by MoonWolf. If you can read Japanese, checkout README.ja for whatever he said.

On a 10,000 line file:

    time cat example.csv | ruby fastercsv_benchmark.rb

    real	0m8.804s
    user	0m8.502s
    sys	0m0.304s

    time cat example.csv | ruby csvscan_benchmark.rb 

    real	0m0.860s
    user	0m0.782s
    sys	0m0.088s}
  s.email = ["sandofsky@gmail.com"]
  s.extensions = ["ext/csvscan/extconf.rb"]
  s.extra_rdoc_files = ["README.txt", "History.txt", "Manifest.txt"]
  s.files = ["README.ja", "README.txt", "ext/csvscan/MANIFEST", "ext/csvscan/csvscan.c", "ext/csvscan/csvscan.rl", "ext/csvscan/extconf.rb", "setup.rb", "History.txt", "Manifest.txt", "Rakefile", "test/test_csvscan.rb"]
  s.homepage = %q{http://github.com/sandofsky/csvscan}
  s.rdoc_options = ["--main", "README.txt"]
  s.require_paths = ["ext"]
  s.rubyforge_project = %q{csvscan}
  s.rubygems_version = %q{1.3.3}
  s.summary = %q{This is a packaged version of CSVScan, written by MoonWolf}
  s.test_files = ["test/test_csvscan.rb"]

  if s.respond_to? :specification_version then
    current_version = Gem::Specification::CURRENT_SPECIFICATION_VERSION
    s.specification_version = 3

    if Gem::Version.new(Gem::RubyGemsVersion) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<hoe>, [">= 2.3.3"])
    else
      s.add_dependency(%q<hoe>, [">= 2.3.3"])
    end
  else
    s.add_dependency(%q<hoe>, [">= 2.3.3"])
  end
end
