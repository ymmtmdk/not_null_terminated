# NotNullTerminated

Handle not null terminated string.

The core code of this gem was written by naruse-san http://blade.nagaokaut.ac.jp/cgi-bin/scat.rb/ruby/ruby-dev/48598

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'not_null_terminated', github: "ymmtmdk/not_null_terminated"
```

And then execute:

    $ bundle

## Usage

```ruby
require 'not_null_terminated'
require 'minitest_helper'

class TestNotNullTerminated < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::NotNullTerminated::VERSION
  end

  def test_it_does_something_useful
    str = NotNullTerminatedString.new("foo")
    assert_equal true, str.null_terminated?
    str.chop_without_terminate
    assert_equal "fo", str
    assert_equal false, str.null_terminated?
  end
end
```

## Contributing

1. Fork it ( https://github.com/ymmtmdk/not_null_terminated/fork )
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request
