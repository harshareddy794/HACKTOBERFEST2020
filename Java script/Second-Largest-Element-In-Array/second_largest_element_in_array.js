function getSecondLargest(nums) {
  let MAX = Number.MIN_VALUE;
  let MAX_2 = Number.MIN_VALUE;

  for (let val of nums) {
    if (val > MAX) {
      MAX_2 = MAX;
      MAX = val;
    } else if (val > MAX_2 && val !== MAX) MAX_2 = val;
  }

  return MAX_2;
}

console.log(getSecondLargest([5, 3, 6, 6, 2])); // should return 5
