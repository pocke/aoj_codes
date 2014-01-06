while true do
  price, pay = gets.split.map {|x| x.to_i }
  break if price == 0 && pay == 0
  change = pay - price
  sen_yen = change / 1000
  change -= sen_yen * 1000
  gohyaku_yen = change / 500
  change -= gohyaku_yen * 500
  hyaku_yen = change / 100

  puts "#{hyaku_yen} #{gohyaku_yen} #{sen_yen}"
end
