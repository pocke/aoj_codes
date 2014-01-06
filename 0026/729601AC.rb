class Paper

  def initialize
    @paper = Array.new(10).map! { Array.new(10, 0) }
  end

  def drop_ink ink
    if ink.size == 1 then
      drop_point(ink.x, ink.y)
      drop_point(ink.x - 1, ink.y)
      drop_point(ink.x + 1, ink.y)
      drop_point(ink.x, ink.y - 1)
      drop_point(ink.x, ink.y + 1)
    elsif ink.size == 2 then
      (ink.x - 1).upto(ink.x + 1) do |x|
        (ink.y - 1).upto(ink.y + 1) do |y|
          drop_point(x, y)
        end
      end
    else
      (ink.x - 1).upto(ink.x + 1) do |x|
        (ink.y - 1).upto(ink.y + 1) do |y|
          drop_point(x, y)
        end
      end
      drop_point(ink.x - 2, ink.y)
      drop_point(ink.x + 2, ink.y)
      drop_point(ink.x, ink.y - 2)
      drop_point(ink.x, ink.y + 2)
    end
  end

  def count_no_color
    result = 0
    @paper.each do |arr|
      arr.each do |point|
        result += 1 if point == 0
      end
    end
    return result
  end

  def most_dark
    max = 0
    @paper.each do |arr|
      arr.each do |point|
        max = point if max < point
      end
    end
    return max
  end

  private

  def check_point x,y
    if ( 0 <= x && x <= 9 ) && ( 0 <= y && y <= 9 ) then
      return true
    else
      return false
    end
  end

  def drop_point x,y
    @paper[x][y] += 1 if check_point(x, y)
  end

end

class Ink
  def initialize(x, y, size)
    @x, @y, @size = x, y, size
  end
  attr :x, :y, :size
end

paper = Paper.new
while true
  line = gets
  break if line == nil
  x, y, size = line.split(',').map{|i| i.to_i}
  ink = Ink.new(x, y, size)
  paper.drop_ink(ink)
end

puts paper.count_no_color
puts paper.most_dark
