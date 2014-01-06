require 'prime'
$<.map(&:to_i).each do |line|
  small = (line-1).downto(0).find{|x| x.prime?}
  large = (line+1).upto(line*2).find{|x| x.prime?}
  puts "#{small} #{large}"
end