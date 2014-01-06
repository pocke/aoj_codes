while true
  dataset_num = gets.chomp
  break if dataset_num == '0'     #終端に達したらbreak
  dataset = Hash.new(0)
  dataset_num.to_i.times do 
    stdin = gets.chomp
    stdin = stdin.split(' ')
    dataset[stdin[0].to_sym] += stdin[1].to_i * stdin[2].to_i
  end
  flag = true
  dataset.each do |key, value|
    if value >= 1_000_000 
      puts key
      flag = false
    end
  end
  puts 'NA' if flag
end
