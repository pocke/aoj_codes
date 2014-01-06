class Hand
  def initialize(cards)
    @cards = cards.sort
  end

  def what_hand
    case
    when is_four_card?
      'four card'
    when is_full_house?
      'full house'
    when is_straight?
      'straight'
    when is_three_card?
      'three card'
    when is_two_pair?
      'two pair'
    when is_one_pair?
      'one pair'
    else
      'null'
    end
  end

  private

  def is_one_pair?
    is_n_card?(2)
  end

  def is_two_pair?
    ( is_n_card?(2, @cards[0,2]) and is_n_card?(2, @cards[2,2]) ) or
    ( is_n_card?(2, @cards[0,2]) and is_n_card?(2, @cards[3,2]) ) or
    ( is_n_card?(2, @cards[1,2]) and is_n_card?(2, @cards[3,2]) )
  end

  def is_three_card?
    is_n_card?(3)
  end

  def is_straight?
    return true if @cards.inject do |x,y|
                     break if x + 1 != y
                     y
                   end
    return true if @cards[1] == 10 and @cards[2] == 11 and @cards[3] == 12 and
                   @cards[4] == 13 and @cards[0] == 1
    false
  end

  def is_full_house?
    ( is_n_card?(3, @cards[0..2]) and is_n_card?(2, @cards[3..4]) ) or
    ( is_n_card?(2, @cards[0..1]) and is_n_card?(3, @cards[2..4]) )
  end

  def is_four_card?
    is_n_card?(4)
  end

  def is_n_card?(n, cards = @cards)
    cards.each_cons(n){|a|return true if a.all?{|x|x == a[0]}}
    false
  end
end

while gets do
  hand = Hand.new($_.split(?,).map(&:to_i))
  puts hand.what_hand
end