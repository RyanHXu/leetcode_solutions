# https://leetcode.com/discuss/interview-question/278341/Uber-phone-interview-Number-of-distinct-subarrays-with-at-most-k-odd-elements/265140


def evenSubarray(arr, k):
    res = set()
    left, right, odd_num = 0, 0, 0
    while right < len(arr):
        if arr[right] % 2 == 1:
            odd_num += 1

        while odd_num > k and left < right:
            if arr[left] % 2 == 1:
                odd_num -= 1
            left += 1

        for left_start in range(left, right + 1):
            res.add(",".join(map(str, arr[left_start:right + 1])))
        right += 1
    return len(res)


nums = [3, 2, 3, 4]
k = 1
print(evenSubarray(nums,k))