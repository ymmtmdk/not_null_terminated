require 'minitest_helper'

class TestNotNullTerminated < MiniTest::Unit::TestCase
  def test_that_it_has_a_version_number
    refute_nil ::NotNullTerminated::VERSION
  end

  def test_it_does_something_useful
    assert false
  end
end
