class Fixnum
def/o
r=self.fdiv(o)
r<0?r.ceil: r.floor
end
end
gets
$<.map{|x|p eval x[0..-3]}