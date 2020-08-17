import QtQuick 2.15
import QtMultimedia 5.9

Item {
  property bool shouldPlayMusic
  property alias musicSource: playMusicId.source

  onShouldPlayMusicChanged: {
    tryStopMusic()
    tryPlayMusic()
  }

  Audio {
    id: playMusicId

    loops: Audio.Infinite
    source: ""
    volume: 0.2
  }
  SoundEffect {
    id: solvedSoundId
    volume: 0.4
  }

  function stop() {
    playMusicId.stop()
  }

  function tryPlaySoundEffect() {
    if (shouldPlayMusic) {
      solvedSoundId.source = "qrc:/view/music/cheering.wav"
      solvedSoundId.play()
    }
  }

  function tryPlayMusic() {
    if (shouldPlayMusic && playMusicId.source !== undefined
        && playMusicId.source !== "")
      playMusicId.play()
  }

  function tryStopMusic() {
    if (!shouldPlayMusic)
      playMusicId.stop()
  }
}
