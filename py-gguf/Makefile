# $NetBSD$

DISTNAME=	gguf-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gguf/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ggml.ai/
COMMENT=	Python package for writing binary files in the GGUF format
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-sentenceppiece>=0.1.98:../../textproc/py-sentencepiece
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.27:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
