require "bundler/gem_tasks"
require "rake/testtask"

Rake::TestTask.new(:test) do |t|
  t.libs << "test"
end

task :default => :test

require "rake/extensiontask"

Rake::ExtensionTask.new("not_null_terminated") do |ext|
  ext.lib_dir = "lib/not_null_terminated"
end
