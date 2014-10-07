require "not_null_terminated/version"
require "not_null_terminated/not_null_terminated"

class NotNullTerminatedString < String
  include NotNullTerminated
end
