type stream('a);
type scheduler;

[@bs.module "@most/core"] external runEffects : (stream('a), scheduler) => Js.Promise.t(unit) = "";