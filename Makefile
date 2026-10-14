PROJECT = unicorn5
CC = gcc
CFLAGS =
LFLAGS =
INCDIR =
INCS =
LIBDIR = -L/usr/X11/lib
LIBS = -lX11 -lRcs -lm
DEFS = -DX -DUNIX -O3 -Wall -DUSEX
HEADERS = header.h maps.h objects.h world.h gen.h lore.h monsters.h recipe.h spells.h
OBJS = \
	adjustabilities.o \
	advancement.o \
	advancestat.o \
	area9.o \
	area25.o \
	area49.o \
	arenamoveenemy.o \
	arenamoveparty.o \
	autodetect.o \
	bank.o \
	blind.o \
	buyhouse.o \
	castspell.o \
	cavalier.o \
	cave.o \
	checkencounter.o \
	checkintrinsic.o \
	checkmonkweapon.o \
	checknoble.o \
	checkscores.o \
	checkspell1.o \
	clearprompt.o \
	closedoor.o \
	combat.o \
	combathelp.o \
	copymap.o \
	crafting.o \
	darttrap.o \
	deadmonster.o \
	decode.o \
	discover.o \
	dispchar.o \
	displayabilities.o \
	doblink.o \
	doexchange.o \
	dosleep.o \
	drain.o \
	dragondice.o \
	dungeonhelp.o \
	enemymissile.o \
	eshter.o \
	exist.o \
	fear.o \
	findgen.o \
	finditemslot.o \
	findlinkeditem.o \
	findlore.o \
	fire.o \
	fixability.o \
	fixname.o \
	gainexp.o \
	gamble.o \
	getalign.o \
	getclass.o \
	getdir.o \
	gethealth.o \
	getname.o \
	getrace.o \
	getsex.o \
	getshopitems.o \
	getspellname.o \
	gobottom.o \
	godown.o \
	goship.o \
	goup.o \
	haggle.o \
	hasintrinsic.o \
	hasspell.o \
	healing.o \
	houseinventory.o \
	inkey.o \
	insight.o \
	inventory.o \
	invvalid.o \
	intrinsiccount.o \
	itemcost.o \
	library.o \
	load.o \
	lockdoor.o \
	main.o \
	make_c.o \
	make_h.o \
	make_n.o \
	makechar.o \
	makemap.o \
	makestr.o \
	manacost.o \
	missile.o \
	missile9.o \
	mounts.o \
	moveenemy.o \
	movesnake.o \
	msg.o \
	mval.o \
	nap.o \
	needed.o \
	newmonth.o \
	newpawn.o \
	newspell.o \
	noise.o \
	opendoor.o \
	packit.o \
	packitem.o \
	party.o \
	pawn.o \
	placeobject.o \
	poisontrap.o \
	printrec.o \
	prompt.o \
	r_missile.o \
	readsprites.o \
	removeplayer.o \
	removelandplayer.o \
	reversebyte.o \
	save.o \
	sayword.o \
	school.o \
	selectsprite.o \
	shop.o \
	showalign.o \
	showheadings.o \
	showhealth.o \
	showflt.o \
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
	showspot.o \
	showsprite.o \
	sleeptrap.o \
	specials.o \
	sqr.o \
	stockencounter.o \
	stockmonsters.o \
	stocktown.o \
	stocktreasure.o \
	super.o \
	taketime.o \
	tavern.o \
	teleport.o \
	teleporttrap.o \
	temple.o \
	terminal.o \
	title.o \
	touch.o \
	travel.o \
	trunc.o \
	unpack.o \
	upland.o \
	uplandhelp.o \
	upper.o \
	urandom.o \
	urandomize.o \
	view.o \
	wizard.o \
	writefont.o \
	yesno.o

$(PROJECT): $(OBJS)
	$(CC) $(LFLAGS) $(DEFS) $(LIBDIR) $(LIBS) -o $(PROJECT) $(OBJS)

maps.h: mapcnvt map11.map map12.map map13.map map14.map map21.map map22.map map23.map map24.map map31.map map32.map map33.map map34.map eshter.map generic.map radon.map marduk.map nichor.map village.map
	./mapcnvt > maps.h

mapcnvt: mapcnvt.o
	$(CC) $(LFLAGS) $(LIBDIR) $(LIBS) -o mapcnvt mapcnvt.o

.c.o:
	$(CC) $(CFLAGS) $(DEFS) $(INCDIR) $(INCS) -c $<

install: unicorn
	cp unicorn /usr/games/unicorn
clean:
	-rm *.o
	-rm mapcnvt
	-rm $(PROJECT)

advancestat.o:      $(HEADERS) advancestat.c
advancement.o:      $(HEADERS) advancement.c
adjustabilities.o:  $(HEADERS) adjustabilities.c
area9.o:            $(HEADERS) area9.c
area25.o:           $(HEADERS) area25.c
area49.o:           $(HEADERS) area49.c
arenamoveenemy.o:   $(HEADERS) arenamoveenemy.c
arenamoveparty.o:   $(HEADERS) arenamoveparty.c
autodetect.o:       $(HEADERS) autodetect.c
bank.o:             $(HEADERS) bank.c
blind.o:            $(HEADERS) blind.c
buyhouse.o:         $(HEADERS) buyhouse.c
castspell.o:        $(HEADERS) castspell.c
cavalier.o:         $(HEADERS) cavalier.c
cave.o:             $(HEADERS) cave.c
checkencounter.o:   $(HEADERS) checkencounter.c
checkintrinsic.o:   $(HEADERS) checkintrinsic.c
checkmonkweapon.o:  $(HEADERS) checkmonkweapon.c
checknoble.o:       $(HEADERS) checknoble.c
checkscores.o:      $(HEADERS) checkscores.c
checkspell1.o:      $(HEADERS) checkspell1.c
clearprompt.o:      $(HEADERS) clearprompt.c
closedoor.o:        $(HEADERS) closedoor.c
combat.o:           $(HEADERS) combat.c
combathelp.o:       $(HEADERS) combathelp.c
copymap.o:          $(HEADERS) copymap.c
crafting.o:         $(HEADERS) crafting.c
darttrap.o:         $(HEADERS) darttrap.c
deadmonster.o:      $(HEADERS) deadmonster.c
decode.o:           $(HEADERS) decode.c
discover.o:         $(HEADERS) discover.c
dispchar.o:         $(HEADERS) dispchar.c
displayabilities.o: $(HEADERS) displayabilities.c
doblink.o:          $(HEADERS) doblink.c
doexchange.o:       $(HEADERS) doexchange.c
dosleep.o:          $(HEADERS) dosleep.c
dragondice.o:       $(HEADERS) dragondice.c
drain.o:            $(HEADERS) drain.c
dungeonhelp.o:      $(HEADERS) dungeonhelp.c
enemymissile.o:     $(HEADERS) enemymissile.c
eshter.o:           $(HEADERS) eshter.c
exist.o:            $(HEADERS) exist.c
fear.o:             $(HEADERS) fear.c
findgen.o:          $(HEADERS) findgen.c
finditemslot.o:     $(HEADERS) finditemslot.c
findlinkeditem.o:   $(HEADERS) findlinkeditem.c
findlore.o:         $(HEADERS) findlore.c
fire.o:             $(HEADERS) fire.c
fixability.o:       $(HEADERS) fixability.c
fixname.o:          $(HEADERS) fixname.c
gainexp.o:          $(HEADERS) gainexp.c
gamble.o:           $(HEADERS) gamble.c
getalign.o:         $(HEADERS) getalign.c
getclass.o:         $(HEADERS) getclass.c
getdir.o:           $(HEADERS) getdir.c
gethealth.o:        $(HEADERS) gethealth.c
getname.o:          $(HEADERS) getname.c
getrace.o:          $(HEADERS) getrace.c
getsex.o:           $(HEADERS) getsex.c
getshopitems.o:     $(HEADERS) getshopitems.c
getspellname.o:     $(HEADERS) getspellname.c
gobottom.o:         $(HEADERS) gobottom.c
godown.o:           $(HEADERS) godown.c
goship.o:           $(HEADERS) goship.c
goup.o:             $(HEADERS) goup.c
haggle.o:           $(HEADERS) haggle.c
hasintrinsic.o:     $(HEADERS) hasintrinsic.c
hasspell.o:         $(HEADERS) hasspell.c
healing.o:          $(HEADERS) healing.c
houseinventory.o:   $(HEADERS) houseinventory.c
inkey.o:            $(HEADERS) inkey.c
insight.o:          $(HEADERS) insight.c
intrinsiccount.o:   $(HEADERS) intrinsiccount.c
inventory.o:        $(HEADERS) inventory.c
invvalid.o:         $(HEADERS) invvalid.c
itemcost.o:         $(HEADERS) itemcost.c
library.o:          $(HEADERS) library.c
load.o:             $(HEADERS) load.c
lockdoor.o:         $(HEADERS) lockdoor.c
main.o:             $(HEADERS) main.c objects.h
makechar.o:         $(HEADERS) makechar.c
make_c.o:           $(HEADERS) make_c.c
make_h.o:           $(HEADERS) make_h.c
make_n.o:           $(HEADERS) make_n.c
makemap.o:          $(HEADERS) makemap.c
makestr.o:          $(HEADERS) makestr.c
manacost.o:         $(HEADERS) manacost.c
missile.o:          $(HEADERS) missile.c
missile9.o:         $(HEADERS) missile9.c
mounts.o:           $(HEADERS) mounts.c
moveenemy.o:        $(HEADERS) moveenemy.c
movesnake.o:        $(HEADERS) movesnake.c
msg.o:              $(HEADERS) msg.c
mval.o:             $(HEADERS) mval.c
nap.o:              $(HEADERS) nap.c
needed.o:           $(HEADERS) needed.c
newmonth.o:         $(HEADERS) newmonth.c
newpawn.o:          $(HEADERS) newpawn.c
newspell.o:         $(HEADERS) newspell.c
noise.o:            $(HEADERS) noise.c
opendoor.o:         $(HEADERS) opendoor.c
packit.o:           $(HEADERS) packit.c
packitem.o:         $(HEADERS) packitem.c
party.o:            $(HEADERS) party.c
pawn.o:             $(HEADERS) pawn.c
placeobject.o:      $(HEADERS) placeobject.c
poisontrap.o:       $(HEADERS) poisontrap.c
printrec.o:         $(HEADERS) printrec.c
prompt.o:           $(HEADERS) prompt.c
r_missile.o:        $(HEADERS) r_missile.c
readsprites.o:      $(HEADERS) readsprites.c
removelandplayer.o: $(HEADERS) removelandplayer.c
removeplayer.o:     $(HEADERS) removeplayer.c
reversebyte.o:      $(HEADERS) reversebyte.c
save.o:             $(HEADERS) save.c
sayword.o:          $(HEADERS) sayword.c
school.o:           $(HEADERS) school.c
selectsprite.o:     $(HEADERS) selectsprite.c unicorn.xpm
shop.o:             $(HEADERS) shop.c
showalign.o:        $(HEADERS) showalign.c
showflt.o:          $(HEADERS) showflt.c
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
showspot.o:         $(HEADERS) showspot.c
showsprite.o:       $(HEADERS) showsprite.c
sleeptrap.o:        $(HEADERS) sleeptrap.c
specials.o:         $(HEADERS) specials.c
sqr.o:              $(HEADERS) sqr.c
stockencounter.o:   $(HEADERS) stockencounter.c
stockmonsters.o:    $(HEADERS) stockmonsters.c
stocktown.o:        $(HEADERS) stocktown.c
stocktreasure.o:    $(HEADERS) stocktreasure.c
super.o:            $(HEADERS) super.c
taketime.o:         $(HEADERS) taketime.c
tavern.o:           $(HEADERS) tavern.c
temple.o:           $(HEADERS) temple.c
teleport.o:         $(HEADERS) teleport.c
teleporttrap.o:     $(HEADERS) teleporttrap.c
terminal.o:         $(HEADERS) terminal.c
title.o:            $(HEADERS) title.c
touch.o:            $(HEADERS) touch.c
travel.o:           $(HEADERS) travel.c
trunc.o:            $(HEADERS) trunc.c
upland.o:           $(HEADERS) upland.c
uplandhelp.o:       $(HEADERS) uplandhelp.c
upper.o:            $(HEADERS) upper.c
unpack.o:           $(HEADERS) unpack.c
urandom.o:          $(HEADERS) urandom.c
urandomize.o:       $(HEADERS) urandomize.c
view.o:             $(HEADERS) view.c
wizard.o:           $(HEADERS) wizard.c
writefont.o:        $(HEADERS) writefont.c
yesno.o:            $(HEADERS) yesno.c



