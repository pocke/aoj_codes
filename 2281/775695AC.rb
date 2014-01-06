class Char
  def initialize ch
    @value = ch[0]
  end

  def succ
    @value.succ[0]
  end

  def succ!
    @value = self.succ
  end
  
  def to_s
    @value
  end
end

class SwapCipther
  def initialize cipther
    @cipther = cipther
  end

  def decoding i, j
    diff = (i - j).abs
    forward(i, diff)
    forward(j, diff)
    swap(i, j)
  end

  def to_s
    @cipther
  end

  private
  def forward(index, num)
    ch = Char.new(@cipther[index])
    num.times do
      ch.succ!
    end
    @cipther[index] = ch.to_s
  end

  def swap(i, j)
    @cipther[i], @cipther[j] = @cipther[j], @cipther[i]
  end
end

while gets.to_i != 0 do
  n = $_.to_i
  str = gets.chomp;
  cipther = SwapCipther.new(str)
  commands = []
  n.times do
    commands << gets.split.map{|x| x.to_i-1}
  end
  commands.reverse!
  commands.each do |command|
    cipther.decoding(command[0], command[1])
  end
  puts cipther
end