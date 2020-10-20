function isPrime(nr) {
  if (typeof nr === "number" && nr > 1) {
    if (nr % 2 === 0) {
      return nr === 2;
    }
    for (let i = 3; i ** 2 < nr; i += 2) {
      if (nr % i === 0) {
        return false;
      }
    }
    return true;
  }
  return false;
}
