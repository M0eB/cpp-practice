/*

A regular expression is a sequence of characters that defines a set of matching strings.
For this problem we define a simple subset of a fun regular expression language.

A simple regular expression( SRE ) is an alphanumeric character, the metacharacter
. ( dot ), an alphanumeric character or dot followed by the meta character ..( star ), or the
concatenation of two simple regular expressions.For example, a, aW, aW.9, aW.9.,
and aW.•9.are simple regular expressions.
An extended simple regular expression( ESRE ) is an SRE, an SRE prepended with
the metacharacter A, an SRE ended with the metacharacter $, or an SRE prepended

with" and ended with $. The previous SRE examples are ESREs, as are I\a, aW$,
and I\aW.9..$.
First we define what it means for an SRE r to strictly match a string s.Recall s"
denotes the k - th suffix of s,
-If r begins with an alphanumeric character and the next character in r is not
star, then r strictly matches s if that same character is at the start of s, and r1
strictly matches 51.
- If r begins with an alphanumeric character and the next character in r is star,
then r strictly matches 5 if s can be written as 51 concatenated by 52, where 51
consists of zero or more of the same character, and 52 strictly matches r2.
- If r begins with dot and the next character in r is not star, then r strictly matches
s if, 1 strictly matches 51.
- If, begins with dot and the next character in r is star, then' strictly matches 5
if 5 can be written as 51 concatenated with 52, where 51 is of length 0 or more,
and rstrictly matches 52.
Now we define when an ESRE matches a string.Conceptually, the metacharacters
1\ and $ stand for the beginning and end of the string, respectively.An ESRE r that
does not start with" or end with $ matches s if there is a substring t of 5 such that r
strictly matches t.
An ESRE r beginning with 1\ matches s if there is a prefix sl of 5 such that, strictly
matches 51. An ESRE r ending with $ matches 5 if there is a suffix 52 of 5 such that r
strictly matches 52.
The following examples are all concerned with ESREs.aW9 matches any string
containing aW9 as a substring. "a W9 matches aW9 only at the start of a string. aW9$
matches aW9 only at the end of a string.l\aW9$ matches aW9 and nothing else.a.9
matches a89 and xyaW9123 but not aw89.a ...9 matches aw89, and aw ..9 matches
aww9.

Problem 6.23: Design an algorithm that takes a string 5 and a string r, assumed to
be a well - formed ESRE, and checks if r matches s.

*/