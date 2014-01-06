while gets.to_i !=0 do
  adventurers = gets.split.map(&:to_i).sort.reverse
  pon = gon = 0
  adventurers.each do |a|
    pon < gon ? (pon += a) : (gon += a)
  end
  p (pon - gon).abs
end