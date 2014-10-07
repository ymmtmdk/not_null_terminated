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
