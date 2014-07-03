/**
 * Check whether an element is a string with a length greater than 0
 */
function is_string(str) {
  if (typeof str != 'string') {
    return false;
  }
  
  return str.length;
}
