class Fixnum
def/o
self.fdiv(o).to_i
end
end
gets
$<.map{|x|p eval x[0..-3]}