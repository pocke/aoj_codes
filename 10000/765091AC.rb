=begin
Hello World
=end
SCRIPT_LINES__ = { __FILE__ => File.readlines(__FILE__)}
puts SCRIPT_LINES__[__FILE__][1]