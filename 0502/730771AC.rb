class Dice
  def initialize
    @up = 1
    @down = 6
    @front = 2
    @back = 5
    @right = 3
    @left = 4
  end

  def north
    @up, @down, @front, @back = @front, @back, @down, @up
    @up
  end

  def south
    @up, @down, @front, @back = @back, @front, @up, @down
    @up
  end

  def east
    @up, @down, @right, @left = @left, @right, @up, @down
    @up
  end

  def west
    @up, @down, @right, @left = @right, @left, @down, @up
    @up
  end

  def right
    @front, @back, @right, @left = @right, @left, @back, @front
    @up
  end

  def left
    @front, @back, @right, @left = @left, @right, @front, @back
    @up
  end
end

while true do
  n = gets.to_i
  break if n == 0

  dice = Dice.new
  sum = 1
  n.times do 
    command = gets.chomp
    case command
    when 'North' then
      sum += dice.north
    when 'South' then
      sum += dice.south
    when 'East' then
      sum += dice.east
    when 'West' then
      sum += dice.west
    when 'Right' then
      sum += dice.right
    when 'Left' then
      sum += dice.left
    end
  end
  puts sum
end
