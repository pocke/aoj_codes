while true do
  begin
    *length_arr, speed1, speed2 = gets.chomp.split(',').map{|x| x.to_i}
  rescue
    break
  end
  length = length_arr.inject{|sum,n| sum+n}
  l = speed1 * length / ( speed1 + speed2 ).to_f
  le = 0
  length_arr.each_with_index do |len, i|
    le += len
    if le >= l then
      puts i+1
      break
    end
  end
end
