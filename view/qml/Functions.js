function randomColor() {
  return "#" + (0x1000000 + parseInt(Math.random() * 0x1000000)).toString(
        16).substr(-6)
}

function leftZeroPad(number) {
  var s = "00" + number
  return s.substr(s.length - 2)
}

function secondsToHms(seconds) {
  if (seconds === undefined || seconds === 0) {
    return ""
  } else {
    var h = Math.floor(seconds / 3600)
    var m = Math.floor(seconds % 3600 / 60)
    var s = Math.floor(seconds % 3600 % 60)

    return leftZeroPad(h) + ":" + leftZeroPad(m) + ":" + leftZeroPad(s)
  }
}

function removeDuplicates(array) {
  var unique = array.filter(function (elem, index, self) {
    return index === self.indexOf(elem)
  })

  return unique
}

function itemCount(element, array) {
  var length = array.length
  var counter = 0
  for (var i = 0; i < length; i++) {
    if (array[i] === element)
      ++counter
  }
  return counter
}
