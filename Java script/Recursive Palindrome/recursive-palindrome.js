function recursivePalindrome(str) {
  if (typeof str === "string" || typeof str === "number") {
    str = str + "";

    if (str.length <= 1) {
      return true;
    }

    if (str[0] === str[str.length - 1]) {
      return recursivePalindrome(str.substr(1, str.length - 2));
    }
  }
  return false;
}
