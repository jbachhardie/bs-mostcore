type time = int;

type delay = int;

type period = int;

type offset = int;

type stream('a);

type sink('a);

type disposable;

type scheduler;

type clock;

type timer;

type timeline;

type task;

type scheduledTask;

type error;

module Core = {
  [@bs.module "@most/core"]
  external runEffects : (stream('a), scheduler) => Js.Promise.t(unit) = "";
  [@bs.module "@most/core"] external run : (sink('a), scheduler, stream('a)) => unit = "";
  [@bs.module "@most/core"] external empty : unit => stream('a) = "";
  [@bs.module "@most/core"] external never : unit => stream('a) = "";
  [@bs.module "@most/core"] external now : 'a => stream('a) = "";
  [@bs.module "@most/core"] external at : (time, 'a) => stream('a) = "";
  [@bs.module "@most/core"] external periodic : period => stream(unit) = "";
  [@bs.module "@most/core"] external throwError : error => stream(unit) = "";
  [@bs.module "@most/core"] external startWith : ('a, stream('a)) => stream('a) = "";
  [@bs.module "@most/core"]
  external continueWith : (unit => stream('a), stream('a)) => stream('a) = "";
  [@bs.module "@most/core"] external map : ('a => 'b, stream('a)) => stream('b) = "";
  [@bs.module "@most/core"] external constant : ('a, stream('b)) => stream('a) = "";
  [@bs.module "@most/core"] external tap : ('a => 'b, stream('a)) => stream('a) = "";
  [@bs.module "@most/core"] external ap : (stream('a => 'b), stream('a)) => stream('b) = "";
  [@bs.module "@most/core"] external scan : (('b, 'a) => 'b, 'b, stream('a)) => stream('b) = "";
  [@bs.module "@most/core"]
  external loop :
    (
      ('b, 'a) =>
      {
        .
        "seed": 'b,
        "value": 'c
      },
      'b,
      stream('a)
    ) =>
    stream('c) =
    "";
  [@bs.module "@most/core"]
  external zipItems : (('a, 'b) => 'c, array('a), stream('b)) => stream('c) = "";
  [@bs.module "@most/core"] external withItems : (array('a), stream('b)) => stream('a) = "";
  [@bs.module "@most/core"] external switchLatest : stream(stream('a)) => stream('a) = "";
  [@bs.module "@most/core"] external join : stream(stream('a)) => stream('a) = "";
  [@bs.module "@most/core"] external chain : ('a => stream('b), stream('a)) => stream('b) = "";
  [@bs.module "@most/core"] external concatMap : ('a => stream('b), stream('a)) => stream('b) = "";
  [@bs.module "@most/core"]
  external mergeConcurrently : (int, stream(stream('a))) => stream('a) = "";
  [@bs.module "@most/core"]
  external mergeMapConcurrently : ('a => stream('b), int, stream(stream('a))) => stream('b) = "";
  [@bs.module "@most/core"] external merge : (stream('a), stream('a)) => stream('a) = "";
  [@bs.module "@most/core"] external mergeArray : array(stream('a)) => stream('a) = "";
  [@bs.module "@most/core"]
  external combine : (('a, 'b) => 'c, stream('a), stream('b)) => stream('c) = "";
  [@bs.module "@most/core"]
  external zip : (('a, 'b) => 'c, stream('a), stream('b)) => stream('c) = "";
  [@bs.module "@most/core"] external sample : (stream('a), stream('b)) => stream('a) = "";
  [@bs.module "@most/core"]
  external snapshot : (('a, 'b) => 'c, stream('a), stream('b)) => stream('c) = "";
};