PROJECT = unicorn
INSTALLDIR = /usr/local/games/
CC = gcc
CFLAGS =
LFLAGS =
INCDIR =
INCS =

.PHONY: clean dist

# Defs for compiling with UNIX/Text
#DEFS = -DUNIX -O3 -Wall -DASCII -DHC 
#LIBDIR = 
#LIBS = 

# Defs for compiling with UNIX/X-Windows
DEFS = -DUNIX -O3 -Wall -DX -DHC 
LIBDIR = -L/usr/X11/lib
LIBS = -lX11

# Defs for compiling with MINGW for native Windows binary
#DEFS = -DUNIX -O3 -Wall -DASCII -DHC -DMINGW  -UWIN32
#LIBDIR = 
#LIBS = 

# Defs for compiling with MINGW for native Windows binary graphics
#DEFS = -DUNIX -O3 -Wall -DWIN32 -DMINGW -DHC 
#LIBDIR = 
#LIBS = -s -lgdi32 -lcomctl32 -Wl,--subsystem,windows

#HEADERS = header.h maps.h objects.h world.h gen.h lore.h monsters.h recipe.h spells.h races.h classes.h trophies.h Makefile
HEADERS = header.h maps.h objects.h world.h gen.h lore.h monsters.h recipe.h spells.h races.h classes.h trophies.h
OBJS = \
	activate.o \
	addskill.o \
	adjustabilities.o \
	adjustmap.o \
	advancement.o \
	advancestat.o \
	aoe.o \
	area9.o \
	area25.o \
	area49.o \
	arena.o \
	arenaheal.o \
	arenamoveenemy.o \
	arenamoveparty.o \
	autodetect.o \
	bank.o \
	blind.o \
	blindtrap.o \
	builddungeon.o \
	buyhouse.o \
	buyprice.o \
	cansee.o \
	castspell.o \
	cast_spell.o \
	cavalier.o \
	cave.o \
	charattributes.o \
	charmmonster.o \
	checkautos.o \
	checkclasschange.o \
	checkencounter.o \
	checkintrinsic.o \
	checklevelclear.o \
	checkmonkweapon.o \
	checkmount.o \
	checknoble.o \
	checkscores.o \
	checkspell1.o \
	clearprompt.o \
	closedoor.o \
	combathelp.o \
	compass.o \
	convertrecipe.o \
	converttime.o \
	copymap.o \
	crafting.o \
	darttrap.o \
	datacard.o \
	deadmonster.o \
	decode.o \
	discover.o \
	dispchar.o \
	displayabilities.o \
	dmgreduction.o \
	doblink.o \
	doexchange.o \
	doget.o \
	doheal.o \
	dosleep.o \
	drain.o \
	dragondice.o \
	dungeonhelp.o \
	effect.o \
	enemyhit.o \
	enemymissile.o \
	exist.o \
	fear.o \
	feardir.o \
	figuredamage.o \
	findgen.o \
	finditemslot.o \
	findlinkeditem.o \
	findlore.o \
	findpath.o \
	fire.o \
	firetrap.o \
	firewand.o \
	fireweapon.o \
	fixability.o \
	fixname.o \
	fkeys.o \
	gainexp.o \
	gamble.o \
	getalign.o \
	getcity.o \
	getclass.o \
	getdir.o \
	getdungeon.o \
	gethealth.o \
	getitem.o \
	getlinkedmonst.o \
	getlinkedmsg.o \
	getmonster.o \
	getname.o \
	getrace.o \
	getsex.o \
	getskill.o \
	getshopitems.o \
	getshoprecipes.o \
	getshopspells.o \
	getspellname.o \
	gobottom.o \
	godown.o \
	gold.o \
	goship.o \
	goup.o \
	graphics.o \
	haggle.o \
	hasintrinsic.o \
	hassocket.o \
	hasspell.o \
	healing.o \
	houseinventory.o \
	inkey.o \
	inroom.o \
	insight.o \
	inventory.o \
	invvalid.o \
	intrinsiccount.o \
	isweapon.o \
	itemcolor.o \
	itemcost.o \
	itemdir.o \
	levellegacy.o \
	library.o \
	lightroom.o \
	load.o \
	load57.o \
	loadgear.o \
	loadlevel.o \
	log.o \
	lockdoor.o \
	los.o \
	magicadjust.o \
	main.o \
	make_a.o \
	make_c.o \
	make_h.o \
	make_n.o \
	makechar.o \
	makemap.o \
	makestr.o \
	manacost.o \
	mapgen.o \
	mapgenold.o \
	maxdamage.o \
	meleehit.o \
	minimap.o \
	missile.o \
	mounts.o \
	moveenemy.o \
	movesnake.o \
	msg.o \
	mutable.o \
	mutalegend.o \
	mval.o \
	nap.o \
	needed.o \
	newgame.o \
	newmonth.o \
	newpawn.o \
	newspell.o \
	noise.o \
	opendoor.o \
	packit.o \
	packitem.o \
	party.o \
	passable.o \
	pawn.o \
	pittrap.o \
	placeobject.o \
	poisontrap.o \
	printrec.o \
	processconfig.o \
	processoption.o \
	prompt.o \
	r_missile.o \
	rcsrandom.o \
	readsprites.o \
	recipestring.o \
	reducedmg.o \
	removeplayer.o \
	removelandplayer.o \
	reversebyte.o \
	roottrap.o \
	save.o \
	savegear.o \
	savelevel.o \
	sayword.o \
	scalemonster.o \
	school.o \
	selectsprite.o \
	settitle.o \
	settrap.o \
	shop.o \
	showalign.o \
	showheadings.o \
	showhealth.o \
	showfkeys.o \
	showflt.o \
	showgain.o \
	showgen.o \
	showinventory.o \
	showicons.o \
	showint.o \
	showland.o \
	showlandplayer.o \
	showlog.o \
	showlore.o \
	showmap.o \
	showmessages.o \
	shownumber.o \
	showplayer.o \
	showquest.o \
	showscores.o \
	showscreen.o \
	showside.o \
	showsmland.o \
	showsmmap.o \
	showspell.o \
	showspot.o \
	showsprite.o \
	showstats.o \
	sleeptrap.o \
	sortshopitems.o \
	specials.o \
	sqr.o \
	statsdodamage.o \
	statstakedamage.o \
	stockencounter.o \
	stockmonsters.o \
	stocktown.o \
	stocktreasure.o \
	super.o \
	taketime.o \
	target.o \
	tavern.o \
	teleport.o \
	teleporttrap.o \
	temple.o \
	terminal.o \
	throw.o \
	thrownpotion.o \
	title.o \
	touch.o \
	transcribe.o \
	travel.o \
	triggertrap.o \
	trophies.o \
	trunc.o \
	unpack.o \
	upland.o \
	uplandhelp.o \
	upper.o \
	urandom.o \
	urandomize.o \
	usecompass.o \
	useitem.o \
	validmove.o \
	view.o \
	winner.o \
	wizard.o \
	writefont.o \
	yesno.o

$(PROJECT): $(OBJS)
	$(CC) $(LFLAGS) $(DEFS) $(LIBDIR) -o $(PROJECT) $(OBJS) $(LIBS)

maps.h: mapcnvt map11.map map12.map map13.map map14.map map21.map map22.map map23.map map24.map map31.map map32.map map33.map map34.map eshter.map generic.map radon.map marduk.map nichor.map village.map
	./mapcnvt > maps.h

mapcnvt: mapcnvt.o
	$(CC) $(LFLAGS) $(LIBDIR) $(LIBS) -o mapcnvt mapcnvt.o

.c.o:
	$(CC) $(CFLAGS) $(DEFS) $(INCDIR) $(INCS) -c $<

docs:   makedoc
	./makedoc -ls80 -rm5 -lm5 -tp5 -ps2 unicorn

makedoc: makedoc.o
	$(CC) $(LFLAGS) $(LIBDIR) $(LIBS) -o makedoc makedoc.o

dist:
	-mkdir dist
	-mkdir dist/unicorn
	-mkdir dist/unicorn/src
	cp *.c dist/unicorn/src
	cp *.h dist/unicorn/src
	cp *.map dist/unicorn/src
	cp ../Documentation/unicorn.doc dist/unicorn/src
	cp unicorn.xpm dist/unicorn/src
	cp unicorn.text dist/unicorn/src
	cp unicorn.cfg dist/unicorn/src
	cat Makefile | sed -e 's///' > dist/unicorn/src/Makefile
	-rm dist/unicorn/src/makedoc.c
	cd dist; \
	   tar cvfz unicorn_src.tgz ./unicorn/src/*
	

install: unicorn
	cp unicorn $(INSTALLDIR)

clean:
	-rm *.o
	-rm mapcnvt
	-rm $(PROJECT)

activate.o:         $(HEADERS) activate.c
addskill.o:         $(HEADERS) addskill.c
advancestat.o:      $(HEADERS) advancestat.c
advancement.o:      $(HEADERS) advancement.c
adjustmap.o:        $(HEADERS) adjustmap.c
adjustabilities.o:  $(HEADERS) adjustabilities.c
aoe.o:              $(HEADERS) aoe.c
area9.o:            $(HEADERS) area9.c
area25.o:           $(HEADERS) area25.c
area49.o:           $(HEADERS) area49.c
arena.o:            $(HEADERS) arena.c
arenaheal.o:        $(HEADERS) arenaheal.c
arenamoveenemy.o:   $(HEADERS) arenamoveenemy.c
arenamoveparty.o:   $(HEADERS) arenamoveparty.c
autodetect.o:       $(HEADERS) autodetect.c
bank.o:             $(HEADERS) bank.c
blind.o:            $(HEADERS) blind.c
blindtrap.o:        $(HEADERS) blindtrap.c
builddungeon.o:     $(HEADERS) builddungeon.c
buyhouse.o:         $(HEADERS) buyhouse.c
buyprice.o:         $(HEADERS) buyprice.c
cansee.o:           $(HEADERS) cansee.c
castspell.o:        $(HEADERS) castspell.c
cast_spell.o:       $(HEADERS) cast_spell.c
cavalier.o:         $(HEADERS) cavalier.c
cave.o:             $(HEADERS) cave.c
charattributes.o:   $(HEADERS) charattributes.c
charmmonster.o:     $(HEADERS) charmmonster.c
checkautos.o:       $(HEADERS) checkautos.c
checkclasschange.o: $(HEADERS) checkclasschange.c
checkencounter.o:   $(HEADERS) checkencounter.c
checkintrinsic.o:   $(HEADERS) checkintrinsic.c
checklevelclear.o:  $(HEADERS) checklevelclear.c
checkmonkweapon.o:  $(HEADERS) checkmonkweapon.c
checkmount.o:       $(HEADERS) checkmount.c
checknoble.o:       $(HEADERS) checknoble.c
checkscores.o:      $(HEADERS) checkscores.c
checkspell1.o:      $(HEADERS) checkspell1.c
clearprompt.o:      $(HEADERS) clearprompt.c
closedoor.o:        $(HEADERS) closedoor.c
combathelp.o:       $(HEADERS) combathelp.c
compass.o:          $(HEADERS) compass.c
convertrecipe.o:    $(HEADERS) convertrecipe.c
converttime.o:      $(HEADERS) converttime.c
copymap.o:          $(HEADERS) copymap.c
crafting.o:         $(HEADERS) crafting.c
darttrap.o:         $(HEADERS) darttrap.c
datacard.o:         $(HEADERS) datacard.c
deadmonster.o:      $(HEADERS) deadmonster.c
decode.o:           $(HEADERS) decode.c
discover.o:         $(HEADERS) discover.c
dispchar.o:         $(HEADERS) dispchar.c
displayabilities.o: $(HEADERS) displayabilities.c
dmgreduction.o:     $(HEADERS) dmgreduction.c
doblink.o:          $(HEADERS) doblink.c
doexchange.o:       $(HEADERS) doexchange.c
doget.o:            $(HEADERS) doget.c
doheal.o:           $(HEADERS) doheal.c
dosleep.o:          $(HEADERS) dosleep.c
dragondice.o:       $(HEADERS) dragondice.c
drain.o:            $(HEADERS) drain.c
dungeonhelp.o:      $(HEADERS) dungeonhelp.c
effect.o:           $(HEADERS) effect.c
enemyhit.o:         $(HEADERS) enemyhit.c
enemymissile.o:     $(HEADERS) enemymissile.c
exist.o:            $(HEADERS) exist.c
fear.o:             $(HEADERS) fear.c
feardir.o:          $(HEADERS) feardir.c
figuredamage.o:     $(HEADERS) figuredamage.c
findgen.o:          $(HEADERS) findgen.c
finditemslot.o:     $(HEADERS) finditemslot.c
findlinkeditem.o:   $(HEADERS) findlinkeditem.c
findlore.o:         $(HEADERS) findlore.c
findpath.o:         $(HEADERS) findpath.c
fire.o:             $(HEADERS) fire.c
firetrap.o:         $(HEADERS) firetrap.c
firewand.o:         $(HEADERS) firewand.c
fireweapon.o:       $(HEADERS) fireweapon.c
fixability.o:       $(HEADERS) fixability.c
fixname.o:          $(HEADERS) fixname.c
fkeys.o:            $(HEADERS) fkeys.c
gainexp.o:          $(HEADERS) gainexp.c
gamble.o:           $(HEADERS) gamble.c
getalign.o:         $(HEADERS) getalign.c
getcity.o:          $(HEADERS) getcity.c
getclass.o:         $(HEADERS) getclass.c
getdir.o:           $(HEADERS) getdir.c
getdungeon.o:       $(HEADERS) getdungeon.c
gethealth.o:        $(HEADERS) gethealth.c
getitem.o:          $(HEADERS) getitem.c
getlinkedmonst.o:   $(HEADERS) getlinkedmonst.c
getlinkedmsg.o:     $(HEADERS) getlinkedmsg.c
getmonster.o:       $(HEADERS) getmonster.c
getname.o:          $(HEADERS) getname.c
getrace.o:          $(HEADERS) getrace.c
getsex.o:           $(HEADERS) getsex.c
getshopitems.o:     $(HEADERS) getshopitems.c
getshoprecipes.o:   $(HEADERS) getshoprecipes.c
getshopspells.o:    $(HEADERS) getshopspells.c
getskill.o:         $(HEADERS) getskill.c
getspellname.o:     $(HEADERS) getspellname.c
gobottom.o:         $(HEADERS) gobottom.c
godown.o:           $(HEADERS) godown.c
gold.o:             $(HEADERS) gold.c
goship.o:           $(HEADERS) goship.c
goup.o:             $(HEADERS) goup.c
graphics.o:         $(HEADERS) rgb.h graphics.h graphics.c
haggle.o:           $(HEADERS) haggle.c
hasintrinsic.o:     $(HEADERS) hasintrinsic.c
hassocket.o:        $(HEADERS) hassocket.c
hasspell.o:         $(HEADERS) hasspell.c
healing.o:          $(HEADERS) healing.c
houseinventory.o:   $(HEADERS) houseinventory.c
inkey.o:            $(HEADERS) inkey.c
inroom.o:           $(HEADERS) inroom.c
insight.o:          $(HEADERS) insight.c
intrinsiccount.o:   $(HEADERS) intrinsiccount.c
inventory.o:        $(HEADERS) inventory.c
invvalid.o:         $(HEADERS) invvalid.c
isweapon.o:         $(HEADERS) isweapon.c
itemcolor.o:        $(HEADERS) itemcolor.c
itemcost.o:         $(HEADERS) itemcost.c
itemdir.o:          $(HEADERS) itemdir.c
levellegacy.o:      $(HEADERS) levellegacy.c
library.o:          $(HEADERS) library.c
lightroom.o:        $(HEADERS) lightroom.c
load.o:             $(HEADERS) load.c
load57.o:           $(HEADERS) load57.c
loadgear.o:         $(HEADERS) loadgear.c
loadlevel.o:        $(HEADERS) loadlevel.c
log.o:              $(HEADERS) log.c
lockdoor.o:         $(HEADERS) lockdoor.c
los.o:              $(HEADERS) los.c
magicadjust.o:      $(HEADERS) magicadjust.c
main.o:             $(HEADERS) main.c objects.h
makechar.o:         $(HEADERS) makechar.c
make_a.o:           $(HEADERS) make_a.c
make_c.o:           $(HEADERS) make_c.c
make_h.o:           $(HEADERS) make_h.c
make_n.o:           $(HEADERS) make_n.c
makemap.o:          $(HEADERS) makemap.c
makestr.o:          $(HEADERS) makestr.c
manacost.o:         $(HEADERS) manacost.c
mapgen.o:           $(HEADERS) mapgen.c
mapgenold.o:        $(HEADERS) mapgenold.c
maxdamage.o:        $(HEADERS) maxdamage.c
meleehit.o:         $(HEADERS) meleehit.c
minimap.o:          $(HEADERS) minimap.c
missile.o:          $(HEADERS) missile.c
mounts.o:           $(HEADERS) mounts.c
moveenemy.o:        $(HEADERS) moveenemy.c
movesnake.o:        $(HEADERS) movesnake.c
msg.o:              $(HEADERS) msg.c
mutable.o:          $(HEADERS) mutable.c
mutalegend.o:       $(HEADERS) mutalegend.c
mval.o:             $(HEADERS) mval.c
nap.o:              $(HEADERS) nap.c
needed.o:           $(HEADERS) needed.c
newgame.o:          $(HEADERS) newgame.c
newmonth.o:         $(HEADERS) newmonth.c
newpawn.o:          $(HEADERS) newpawn.c
newspell.o:         $(HEADERS) newspell.c
noise.o:            $(HEADERS) noise.c
opendoor.o:         $(HEADERS) opendoor.c
packit.o:           $(HEADERS) packit.c
packitem.o:         $(HEADERS) packitem.c
party.o:            $(HEADERS) party.c
passable.o:         $(HEADERS) passable.c
pawn.o:             $(HEADERS) pawn.c
pittrap.o:          $(HEADERS) pittrap.c
placeobject.o:      $(HEADERS) placeobject.c
poisontrap.o:       $(HEADERS) poisontrap.c
printrec.o:         $(HEADERS) printrec.c
processconfig.o:    $(HEADERS) processconfig.c
processoption.o:    $(HEADERS) processoption.c
prompt.o:           $(HEADERS) prompt.c
r_missile.o:        $(HEADERS) r_missile.c
rcsrandom.o:        $(HEADERS) rcsrandom.c
readsprites.o:      $(HEADERS) readsprites.c
recipestring.o:     $(HEADERS) recipestring.c
reducedmg.o:        $(HEADERS) reducedmg.c
removelandplayer.o: $(HEADERS) removelandplayer.c
removeplayer.o:     $(HEADERS) removeplayer.c
reversebyte.o:      $(HEADERS) reversebyte.c
roottrap.o:         $(HEADERS) roottrap.c
save.o:             $(HEADERS) save.c
savegear.o:         $(HEADERS) savegear.c
savelevel.o:        $(HEADERS) savelevel.c
sayword.o:          $(HEADERS) sayword.c
scalemonster.o:     $(HEADERS) scalemonster.c
school.o:           $(HEADERS) school.c
selectsprite.o:     $(HEADERS) selectsprite.c unicorn.xpm unicorn.text
settitle.o:         $(HEADERS) settitle.c
settrap.o:          $(HEADERS) settrap.c
shop.o:             $(HEADERS) shop.c
showalign.o:        $(HEADERS) showalign.c
showfkeys.o:        $(HEADERS) showfkeys.c
showflt.o:          $(HEADERS) showflt.c
showgain.o:         $(HEADERS) showgain.c
showgen.o:          $(HEADERS) showgen.c
showheadings.o:     $(HEADERS) showheadings.c
showhealth.o:       $(HEADERS) showhealth.c
showicons.o:        $(HEADERS) showicons.c
showint.o:          $(HEADERS) showint.c
showinventory.o:    $(HEADERS) showinventory.c
showland.o:         $(HEADERS) showland.c
showlandplayer.o:   $(HEADERS) showlandplayer.c
showlog.o:          $(HEADERS) showlog.c
showlore.o:         $(HEADERS) showlore.c
showmap.o:          $(HEADERS) showmap.c
showmessages.o:     $(HEADERS) showmessages.c
shownumber.o:       $(HEADERS) shownumber.c
showplayer.o:       $(HEADERS) showplayer.c
showquest.o:        $(HEADERS) showquest.c
showscores.o:       $(HEADERS) showscores.c
showscreen.o:       $(HEADERS) showscreen.c
showside.o:         $(HEADERS) showside.c
showsmland.o:       $(HEADERS) showsmland.c
showsmmap.o:        $(HEADERS) showsmmap.c
showspell.o:        $(HEADERS) showspell.c
showspot.o:         $(HEADERS) showspot.c
showsprite.o:       $(HEADERS) showsprite.c
showstats.o:        $(HEADERS) showstats.c
sleeptrap.o:        $(HEADERS) sleeptrap.c
sortshopitems.o:    $(HEADERS) sortshopitems.c
specials.o:         $(HEADERS) specials.c
sqr.o:              $(HEADERS) sqr.c
statsdodamage.o:    $(HEADERS) statsdodamage.c
statstakedamage.o:    $(HEADERS) statsdodamage.c
stockencounter.o:   $(HEADERS) stockencounter.c
stockmonsters.o:    $(HEADERS) stockmonsters.c
stocktown.o:        $(HEADERS) stocktown.c
stocktreasure.o:    $(HEADERS) stocktreasure.c
super.o:            $(HEADERS) super.c
taketime.o:         $(HEADERS) taketime.c
target.o:           $(HEADERS) target.c
tavern.o:           $(HEADERS) tavern.c
temple.o:           $(HEADERS) temple.c
teleport.o:         $(HEADERS) teleport.c
teleporttrap.o:     $(HEADERS) teleporttrap.c
terminal.o:         $(HEADERS) terminal.c
throw.o:            $(HEADERS) throw.c
thrownpotion.o:     $(HEADERS) thrownpotion.c
title.o:            $(HEADERS) title.c
touch.o:            $(HEADERS) touch.c
transcribe.o:       $(HEADERS) transcribe.c
travel.o:           $(HEADERS) travel.c
triggertrap.o:      $(HEADERS) triggertrap.c
trophies.o:         $(HEADERS) trophies.c
trunc.o:            $(HEADERS) trunc.c
upland.o:           $(HEADERS) upland.c
uplandhelp.o:       $(HEADERS) uplandhelp.c
upper.o:            $(HEADERS) upper.c
unpack.o:           $(HEADERS) unpack.c
urandom.o:          $(HEADERS) urandom.c
urandomize.o:       $(HEADERS) urandomize.c
usecompass.o:       $(HEADERS) usecompass.c
useitem.o:          $(HEADERS) useitem.c
validmove.o:        $(HEADERS) validmove.c
view.o:             $(HEADERS) view.c
winner.o:           $(HEADERS) winner.c
wizard.o:           $(HEADERS) wizard.c
writefont.o:        $(HEADERS) writefont.c
yesno.o:            $(HEADERS) yesno.c



