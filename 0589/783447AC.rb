class String
  alias nya <=>

  def <=> other
    self.size == other.size ? self.nya(other) : self.size <=> other.size
  end
end

product = Hash.new(0)
gets.to_i.times do
  name, num = gets.split
  product[name] += num.to_i
end
arr = product.sort
arr.each do |item|
  puts "#{item[0]} #{item[1]}"
end