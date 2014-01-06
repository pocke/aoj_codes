def up2words str
  low2words(str)[1..-1]
end

def low2words str
  str.gsub! /([A-Z])/, '*\1'
  str.split(?*).map &:downcase
end

def under2wods str
  str.split ?_
end

def what_case str
  return ?D if str.include? ?_
  return ?U if str[0] =~ /[A-Z]/
  return ?L
end

def words2up words
  words.map(&:capitalize).join
end

def words2low words
  result = words2up(words)
  result[0] = result[0].downcase
  result
end

def words2under words
  words.join ?_
end

$<.each do |line|
  str, rule = line.chomp.split
  break if rule == ?X
  str_rule = what_case str
  words = case str_rule
          when ?U
            up2words str
          when ?L
            low2words str
          when ?D
            under2wods str
          end
  result = case rule
           when ?U
             words2up words
           when ?L
             words2low words
           when ?D
             words2under words
           end
  puts result
end