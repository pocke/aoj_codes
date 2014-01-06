class Decode

  @@decode_table = [nil,
    [nil, ?a, ?b, ?c, ?d, ?e],
    [nil, ?f, ?g, ?h, ?i, ?j],
    [nil, ?k, ?l, ?m, ?n, ?o],
    [nil, ?p, ?q, ?r, ?s, ?t],
    [nil, ?u, ?v, ?w, ?x, ?y],
    [nil, ?z, ?., ??, ?!, ' '],
  ]

  def self.decode(str)
    return 'NA' if str.size.odd?
    return 'NA' if str[/[^1-6]/]
    result = ''

    (str.size / 2).times do |index|
      i = str[index * 2].to_i
      j = str[index * 2 + 1].to_i
      ch = @@decode_table[i][j]
      return 'NA' if ch == nil
      result << ch
    end

    result
  end
end

$<.map do |line|
  puts Decode.decode(line.chomp)
end